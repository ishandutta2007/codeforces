#include <bits/stdc++.h>
using namespace std;
void solve(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if(d > (a-1) + (b-1) + (c-1)) cout << "NO\n";
    else{
        int tmp = max(max(0,a-b-c-1),max(b-a-c-1,c-a-b-1));
        if(d < tmp) cout << "NO\n";
        else cout << "YES\n";
    }
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    int T;
    cin >> T;
    for(int t=0;t<T;t++) solve();
}