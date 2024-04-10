#include <bits/stdc++.h>
using namespace std;
bool iscomp(int x){
    for(int i=2;i*i<=x;i++) if(x%i==0) return true;
    return false;
}
void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    int s=0;
    for(int i=0;i<n;i++){
        cin >> v[i];
        s+=v[i];
    }
    if(iscomp(s)){
        cout << n << "\n";
        for(int i=0;i<n;i++) cout << i+1 << " ";
        cout << "\n";
    }
    else{
        for(int i=0;i<n;i++){
            if(iscomp(s-v[i])){
                cout << n-1 << "\n";
                for(int j=0;j<n;j++) if(i!=j) cout << j+1 << " ";
                cout << "\n";
                return;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for(int i=0;i<T;i++) solve();
}