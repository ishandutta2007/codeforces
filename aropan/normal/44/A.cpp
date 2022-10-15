#include <cstdio>
#include <map>
#include <iostream>
#include <string>


using namespace std;


map <string, int> m;
int n, ans;
string a, b;

int main()
{
/*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
//*/
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        a += " " + b;
        ans += m[a] == 0;
        m[a] = 1;
    }
    printf("%d\n", ans);
    return 0;
}