#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    string s;
    cin >> n >> s;
    
    string answer = "";
    int cnt = 0;
    
    for (int i = 0; i < n; i++)
        if (s[i] == '1')
            cnt++;
        else
        {
            answer += to_string(cnt);
            cnt = 0;
        }
        
    answer += to_string(cnt);
    
    cout << answer << endl;
    
    return 0;
}