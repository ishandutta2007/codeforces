#include <bits/stdc++.h>
using namespace std;

typedef long long                   ll;
typedef long double                 ld;
typedef pair<int,int>               pii;
typedef pair<ll,ll>                 pll;
typedef pair<double,double>         pdd;
typedef pair<ld,ld>                 pld;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define endt                        '\t'
#define ends                        ' '
#define error(x)                    cerr << #x << " = " << x << endl

int main()
{
    int c,r;
    cin >> c >> r;

    string s[c];
    for(int i = 0 ; i < c ; i++)    cin >> s[i];
    for(int i=0;i<c;i++)
    {
        for(int j=0;j<r;j++)
        {
            if(s[i][j] == 'W')
            {
                if(i!=0)
                {
                    if(s[i-1][j] == 'S')
                    {
                        cout << "No" << endl;
                        return 0;
                    }
                }
                if(j!=0)
                {
                    if(s[i][j-1] == 'S')
                    {
                        cout << "No" << endl;
                        return 0;
                    }
                }

                if(i!=c-1)
                {
                    if(s[i+1][j] == 'S')
                    {
                        cout << "No" << endl;
                        return 0;
                    }
                }
                if(j!=r-1)
                {
                    if(s[i][j+1] == 'S')
                    {
                        cout << "No" << endl;
                        return 0;
                    }
                }
            }
        }
    }

    cout << "Yes" << endl;
    for(int i=0;i<c;i++)
    {
        for(int j=0;j<r;j++)
        {
            if(s[i][j] == '.')
            {
                cout << 'D';
            }
            else
            {
                cout << s[i][j];
            }
        }
        cout << endl;
    }



    return 0;
}