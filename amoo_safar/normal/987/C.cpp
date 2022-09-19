#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll MAXN = 3000;

ll s[MAXN];
ll p[MAXN];
int main(){
    ll n;
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> s[i];
    }
    for(int i = 0;i<n;i++){
        cin >> p[i];
    }
    ll mini = -1;
    ll gh,bad;
    for(int j = 1;j<n-1;j++){
        gh = -1;
        bad = -1;
        for(int i =0;i<j;i++){
            if(s[i]<s[j]){
                if(gh == -1){
                    gh = p[i];
                } else {
                    gh = min(gh,p[i]);
                }
            }
        }
        for(int i =j+1;i<n;i++){
            if(s[i]>s[j]){
                if(bad == -1){
                    bad = p[i];
                } else {
                    bad = min(bad,p[i]);
                }
            }
        }
        if((bad != -1) and (gh !=-1)){
            if(mini == -1){
                    mini = gh+bad+p[j];
                } else {
                    mini = min(mini,gh+bad+p[j]);
                }
        }
    }
    cout << mini << endl;
    return 0;
}