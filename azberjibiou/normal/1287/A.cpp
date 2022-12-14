#include <bits/stdc++.h>
#define gibon ios::sync_with_stdio(false); cin.tie(0);
using namespace std;
int main()
{
    gibon
    int T;
    cin >> T;
    while(T--)
    {
        int N;
        cin >> N;
        char A[1010];
        cin >> A;
        int len=strlen(A);
        int ans=0;
        int combo=0;
        bool jogun=false;
        for(int i=0;i<len;i++)
        {
            if(A[i]=='A')
                combo=0, jogun=true;
            else
            {
                if(jogun)
                    combo++;
            }
            ans=max(ans, combo);
        }
        cout << ans << '\n';
    }
}