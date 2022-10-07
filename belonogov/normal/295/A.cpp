#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back
#define fr first
#define sc second
#define epr(...) fprintf(stderr, __VA_ARGS__)


const int maxn = 2e5;

struct event{
    int t;
    long long kof;
    event(){}
    event(int t, long long kof): t(t), kof(kof) {};
};

long long a[maxn];
int l[maxn];
int r[maxn];
long long w[maxn];
int cnt[maxn];
event b[maxn];



bool cmpT(event a, event b){
    return a.t < b.t;
}


int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, m, k, ll, rr;
    long long sum;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < m; i++){
        cin >> l[i] >> r[i] >> w[i];
        l[i]--;
    }

    for(int i = 0; i < k; i++){
        scanf("%d%d", &ll, &rr); ll--;
        b[i * 2] = event(ll, 1);
        b[i * 2 + 1] = event(rr, -1);
    }
    k *= 2;
    sort(b, b + k, cmpT);
    sum = 0;
    int cur = 0;
    for(int i = 0; i < m; i++){
        for(;cur < k && b[cur].t <= i; cur++)
            sum += b[cur].kof;
        cnt[i] = sum;
    }
   /* for(int i = 0; i < m; i++)
        epr("%d ", cnt[i]);
    epr("\n");
    for(int i = 0; i < m; i++)
        epr("%d ", w[i]);
    epr("\n");
*/
    for(int i = 0; i < m; i++){
        b[i * 2] = event(l[i], cnt[i] * w[i]);
        b[i * 2 + 1] = event(r[i], -cnt[i] * w[i]);
    }
    m *= 2;
    sort(b, b + m, cmpT);


    cur = 0;
    sum = 0;
    for(int i = 0; i < n; i++){
        for(;cur < m && b[cur].t <= i; cur++)
            sum += b[cur].kof;
        a[i] += sum;
    }

    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";



    return 0;

}