#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <tuple>
#include <map>

using namespace std;

char nam[100010][7];
int typ[100010];
int num[100010];

vector<int> v1, v2, v3, v4;
vector<pair<string, string>> pri;
vector<int> l, r, com;

string n2c(int n)
{
    char tmp[10];
    sprintf(tmp, "%d", n);
    return tmp;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    bool u;
    int n, c, cnt, t, i, j;
    scanf("%d", &n);

    cnt = 0;
    for(i = 0; i<n; i++)
    {
        scanf("%s%d", nam[i], &typ[i]);
        if(typ[i])
            cnt++;

        c = 0;
        u = 1;
        for(j = 0; nam[i][j]; j++)
        {
            if(!('0'<=nam[i][j]&&nam[i][j]<='9') || nam[i][j]=='0' && j == 0)
            {
                u = 0;
                break;
            }

            c = 10*c + (nam[i][j] - '0');
        }

        if(c > n)
            u = 0;

        if(u)
        {
            num[i] = c;
            com.push_back(c);
        }
        else
            num[i] = -1;
    }

    u = 1;
    for(i = 0; i<n; i++)
    {
        if(num[i] == -1)
        {
            if(typ[i] == 1)
                v3.push_back(i);
            else
                v4.push_back(i);
            u = 0;
        }
        else
        {
            if(num[i] <= cnt && typ[i] == 0)
                v1.push_back(i);
            else if(num[i] > cnt && typ[i] == 1)
                v2.push_back(i);
            u = 0;
        }
    }

    if(u)
    {
        printf("0");
        return 0;
    }

    sort(com.begin(), com.end());
    if(com.empty())
    {
        for(i = 1; i<=n; i++)
        {
            if(i <= cnt)
                l.push_back(i);
            else
                r.push_back(i);
        }
    }
    else
    {
        int pp = 0;
        for(i = 0; i<com.size(); i++)
        {
            for(j = pp+1; j<com[i]; j++)
            {
                if(j <= cnt)
                    l.push_back(j);
                else
                    r.push_back(j);
            }
            pp = com[i];
        }
        for(j = pp+1; j<=n; j++)
        {
            if(j <= cnt)
                l.push_back(j);
            else
                r.push_back(j);
        }
    }

    if(v1.empty() && v2.empty() && v3.empty() && v4.empty())
    {
        printf("0");
        return 0;
    }

    if(v3.empty() && v4.empty())
    {
        for(i = 0;; i++)
        {
            if(i == 100000)
                continue;

            sprintf(nam[n], "%06d", i);

            u = 1;
            for(j = 0; j<n; j++)
            {
                if(strcmp(nam[n], nam[j]) == 0)
                {
                    u = 0;
                    break;
                }
            }
            if(u)
                break;
        }

        if(!v1.empty())
        {
            int x = v1.back();
            v1.pop_back();

            l.push_back(num[x]);

            pri.push_back({ nam[x], nam[n] });
            sprintf(nam[x], "%s", nam[n]);
            v4.push_back(x);
        }
        else if(!v2.empty())
        {
            int x = v2.back();
            v2.pop_back();

            r.push_back(num[x]);

            pri.push_back({ nam[x], nam[n] });
            sprintf(nam[x], "%s", nam[n]);
            v3.push_back(x);
        }
        else
        {
            printf("0");
            return 0;
        }
    }

    while(!l.empty() || !r.empty())
    {
        if(!l.empty() && !v2.empty())
        {
            int x = l.back();
            int y = v2.back();
            l.pop_back();
            v2.pop_back();

            pri.push_back({ nam[y], n2c(x) });
            r.push_back(num[y]);
        }
        else if(!r.empty() && !v1.empty())
        {
            int x = r.back();
            int y = v1.back();
            r.pop_back();
            v1.pop_back();

            pri.push_back({ nam[y], n2c(x) });
            l.push_back(num[y]);
        }
        else if(!l.empty() && !v3.empty())
        {
            int x = l.back();
            int y = v3.back();
            l.pop_back();
            v3.pop_back();

            pri.push_back({ nam[y], n2c(x) });
        }
        else if(!r.empty() && !v4.empty())
        {
            int x = r.back();
            int y = v4.back();
            r.pop_back();
            v4.pop_back();

            pri.push_back({ nam[y], n2c(x) });
        }
        else
            break;
    }

    printf("%d\n", pri.size());
    for(auto p: pri)
        printf("move %s %s\n", p.first.c_str(), p.second.c_str());

    return 0;
}