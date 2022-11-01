#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

typedef long long ll;
typedef pair < int, int > ipair;

const int MAXN = 200000;

int n, a, b, k;
char buf[MAXN];
int shot[MAXN];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> a >> b >> k;
    int cnt = 0;
    int shots = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> buf[i];
        if(buf[i] == '0')
            cnt++;
        else
            cnt = 0;
        if(cnt == b)
        {
            shot[i] = 1;
            cnt = 0;
            shots++;
        }
    }
    for(int i = 0, j = 0; j < a-1; i++)
        if(shot[i] == 1)
        {
            shot[i] = 0;
            j++;
        }
    cout << shots - a + 1 << endl;
    for(int i = 0; i < n; i++)
        if(shot[i] == 1)
            cout << i+1 << ' ';
}