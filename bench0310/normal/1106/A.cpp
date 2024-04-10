#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s[n];
    for(int i=0;i<n;i++) cin >> s[i];
    int cnt=0;
    for(int o=1;o<n-1;o++) for(int i=1;i<n-1;i++) cnt+=(s[o][i]=='X'&&s[o+1][i+1]=='X'&&s[o-1][i-1]=='X'&&s[o-1][i+1]=='X'&&s[o+1][i-1]=='X');
    cout << cnt << endl;
    return 0;
}