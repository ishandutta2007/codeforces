#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

struct seg
{
    ll ans;
    ll pref;
    ll suff;
    ll sum;
};

seg s[55];
int a[5555];
ll b[255555];
int n;
int m;
int l;
const ll inf = 1000000000000LL;

int main()
{
   scanf("%d %d", &n, &m);
   for (int i = 0; i < n; i++)
   {
       scanf("%d", &l);
       for (int j = 0; j < l; j++)
       {
           scanf("%d", &a[j]);
       }
       
       ll sum = 0;
       ll msum = 0;
       ll mx = -inf;
       ll pref = a[0];
       ll suff = a[l-1];
       
       for (int j = 0; j < l; j++)
       {
            mx = max(mx, (ll)a[j]);
           
            msum += a[j];
            sum += a[j];
            if (msum < 0)
                msum = 0;
            else
                mx = max(mx, msum); 
                
            if (j)
            {
                pref = max(pref, sum);
            }
       }
       
       sum = 0;
       
       for (int j = l-1; j >= 0; j--)
       {
           sum += a[j];
           if (j < l-1)
           {
               suff = max(suff, sum);
           }
       }
       
       s[i].ans = mx;
       s[i].pref = pref;
       s[i].suff = suff;
       s[i].sum = sum;
       
       
   } 
   
   ll sum = -inf;
   ll ans = -inf;
   
   for (int i = 0; i < m; i++)
   {
       int t;
       scanf("%d", &t);
       t--;
       
       ans = max(ans, s[t].ans);
       ans = max(ans, max(sum, max(sum + s[t].pref, s[t].pref)));
       sum = max (s[t].suff, sum + s[t].sum);
   }
   
   printf("%I64d", ans);
}