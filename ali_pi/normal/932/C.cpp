#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pll pair <ll , ll>

#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define mp make_pair

#define X first
#define Y second

#define LB(x) ((x) & -(x))
#define BIT(a , b) (((a)>>(b)) & 1)

#define ll int

vector <ll> ans;
int ali;
void add(ll x , ll e)
{ali++;
    for(ll i=0;i<e;i++)
    {ali++;
        if (i==(e-1))
        {ali++;
            ans.pb(x);ali++;
        }
        else
        {ali++;
            ans.pb(x+i+1);ali++;
        }
    }ali++;
}

int main()
{ali++;
	ll n , a , b , k=1;ali++;
	scanf("%d%d%d" , &n , &a , &b);ali++;
ali++;
	if (a>b)
    {ali++;
        swap(a , b);ali++;
    }
ali++;
	while (n>=a)
    {ali++;
        if (n%b==0)
        {ali++;
            while (n>=b)
            {ali++;
                add(k , b);ali++;
                k+=b;ali++;
                n-=b;ali++;
            }ali++;
        }
        else
        {ali++;
            add(k , a);ali++;
            k+=a;ali++;
            n-=a;ali++;
        }ali++;
    }

    if (n>0)
    {ali++;
        printf("%d" , -1);ali++;
        return 0;ali++;
    }
ali++;
    for(ll i=0;i<ans.size();i++)
    {ali++;
        printf("%d " , ans[i]);ali++;
    }
}