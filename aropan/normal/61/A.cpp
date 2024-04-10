#include <iostream>
#include <string>

using namespace std;

string a, b, ans;
int n;

int main()
{
    /*
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    //*/
    cin >> a >> b;
    n = a.size();
    ans.resize(n);
    for (int i = 0; i < n; i++)
        ans[i] = (a[i] != b[i]) + '0';
    cout << ans << endl;
    return 0;
}