#include <iostream>
#include <cstring>

using namespace std;
int n;
char s[3000];
int ans;

int main()
{
    cin >> n;
    cin >> s;
    int k = strlen(s);
    ans = 0;
    for (int i=3; i< k; i++)
        if ((i%n==0)&&(s[i-2]==s[i-1])&&(s[i-2]==s[i-3]))
            ans ++;

    cout << ans;
    return 0;
}