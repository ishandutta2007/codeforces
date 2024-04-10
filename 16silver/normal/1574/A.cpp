#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++) cout << "(";
        for(int j=0;j<i;j++) cout << ")";
        for(int j=i;j<n;j++) cout << "()";
        cout << "\n";
    }
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    int T;
    cin >> T;
    for(int t=0;t<T;t++) solve();
}