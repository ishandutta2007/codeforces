#include <bits/stdc++.h>
#include <math.h>

using namespace std;
typedef long long ll;
ll a[100001];
int main(){
    ll n,u,v;
    cin >> n;
    for(int i=0;i<n-1;i++){
        cin >> u >> v;
        a[u-1]++;
        a[v-1]++;
    }
    ll ind=-1,cnt=0;
    for(int i = 0;i<n;i++){
        if(a[i] == 1){
            cnt ++;
        }
        if(a[i]  > 2){
            if(ind == -1){
                ind = i;
            }else{
                cout << "No";
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    if(ind == -1){
        cout << 1 << endl;
        for(int i =0 ;i<n;i++){
            if(a[i] == 1) cout << i+1 << " ";
        }
    } else {
        cout << cnt << endl;
        for(int i = 0;i<n;i++){
            if(a[i] == 1) cout << i+1 << " "<<ind+1 << endl;
        }
    }
    return 0;
}