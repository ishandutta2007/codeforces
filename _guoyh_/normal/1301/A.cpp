# include <cstdio>
# include <string>
# include <iostream>
# include <algorithm>
# define ll long long
using namespace std;
int t;
string a, b, c;
int main(){
    cin >> t;
    while (t--){
        cin >> a >> b >> c;
        int sz = a.size();
        bool flag = true;
        for (int i = 0; i < sz; i++){
            if (a[i] == c[i] || b[i] == c[i]) continue;
            flag = false;
            break;
        }
        if (flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}