/*
 * DECLARA VECTORII CU O DIMENSIUNE CORECTA !!!! GANDESTE!!!
 */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define maxNM 100005
#define lim 330
#define pb push_back

/*#define cin fin
#define cout fout

ifstream fin("test.in");
ofstream fout("test.out");*/

long i,j,k;
long n,m,q;
long bigCount;
long long v[maxNM],backId[maxNM],bigSum[lim+20],addit[lim+20];
vector<long> sets[maxNM],ap[maxNM];
long pre[lim+20][maxNM];
long x;
long long y;
char c;

void preCalculate() {
    for(size_t i=1;i<=n;i++){
        for(size_t j=0;j<ap[i].size();j++){
            if(sets[ap[i][j]].size() > lim){
                for(size_t k=0;k<ap[i].size();k++){
                    pre[backId[ap[i][j]]][ap[i][k]]++;
                }
            }
        }
    }
}

void sUpdate(long k,long long x){
    for(size_t i=0;i<sets[k].size();i++)
        v[sets[k][i]] += 1*x;
    for(long i=1;i<=bigCount;i++)
        bigSum[i] += 1*pre[i][k]*x;
}

long long sQuery(long k){
    long long ans = 0;
    for(size_t i=0;i<sets[k].size();i++)
        ans += 1*v[sets[k][i]];
    for(long i=1;i<=bigCount;i++)
        ans += 1*pre[i][k]*addit[i];
    return ans;
}

void bUpdate(long k,long long x){
    long id = backId[k],dim = sets[k].size();
    addit[id] += 1*x;
    bigSum[id] += 1*x*dim;
}

long long bQuery(long k){
    long id = backId[k],i;
    long long ans = bigSum[id];
    for(i=1;i<=bigCount;i++)
        if(i != id)
            ans += 1*addit[i]*pre[i][k];
    return ans;
}

int main()
{
    cin >> n >> m >> q;
    for(i=1;i<=n;i++) cin >> v[i];

    for(i=1;i<=m;i++){
        cin >> k;
        if(k > lim) {
            backId[i] = ++bigCount;
        }
        for(j=1;j<=k;j++) {
            cin >> x;
            sets[i].pb(x);
            ap[x].pb(i);
            if(k > lim) bigSum[bigCount] += v[x];
        }
    }

    preCalculate();

    for(i=1;i<=q;i++){
        cin >> c >> x ;
        if(c == '?'){
            long long ans;
            if(sets[x].size() <= lim)
                ans = sQuery(x);
            else
                ans = bQuery(x);
            cout << ans << '\n';
        } else {
            cin >> y;
            if(sets[x].size() <= lim)
                sUpdate(x,y);
            else
                bUpdate(x,y);
        }
    }

    return 0;
}