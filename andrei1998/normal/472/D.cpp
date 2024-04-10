#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;

int mat[2005][2005];
int tata[2005];
int h[2005];

int f(int x){
    if(x!=tata[x])
        tata[x]=f(tata[x]);
    return tata[x];
}

inline bool unite(int a,int b){
    a=f(a);
    b=f(b);

    if(a==b)
        return 0;

    if(h[a]>h[b]){
        tata[b]=a;
    }
    else{
        if(h[a]==h[b])
            h[b]++;
        tata[a]=b;
    }

    return 1;
}

vector<int> tati[2005];

int nod;
bool cmp(const int &a,const int &b){
    return mat[nod][a]<mat[nod][b];
}

int father[2005];

vector<int> graf[2005];
bitset<2005> viz[2005];

int main()
{
    ios_base::sync_with_stdio(false);
    int n=0;

    cin>>n;

    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            cin>>mat[i][j];

    for(i=1;i<=n;i++)
        if(mat[i][i]){
            cout<<"NO\n";
            return 0;
        }

    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(mat[i][j]!=mat[j][i]){
                cout<<"NO\n";
                return 0;
            }

    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(i!=j && !mat[i][j]){
                cout<<"NO\n";
                return 0;
            }

    for(i=1;i<=n;i++){
        tata[i]=i;
        h[i]=1;
    }

    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(i!=j && mat[1][j]+mat[j][i]==mat[1][i])// j e pe lantul 1,i
                tati[i].push_back(j);

    for(i=1;i<=n;i++){
        nod=i;
        sort(tati[i].begin(),tati[i].end(),cmp);
        if(tati[i].size())
            father[i]=*(tati[i].begin());
    }

    for(i=2;i<=n;i++)
        if(!father[i]){
            cout<<"NO\n";
            return 0;
        }

    for(i=2;i<=n;i++)
        if(!unite(i,father[i])){
            cout<<"NO\n";
            return 0;
        }

    for(i=2;i<=n;i++){
        graf[father[i]].push_back(i);
        graf[i].push_back(father[i]);
    }

    vector<int>::iterator it;
    for(i=1;i<=n;i++) //De unde verificam
        for(j=1;j<=n;j++){
            for(vector<int>::iterator it=graf[j].begin();it!=graf[j].end();it++)
                if(mat[i][j]+mat[j][*it]<mat[i][*it]){
                    cout<<"NO\n";
                    return 0;
                }
                else if(mat[i][j]+mat[j][*it]==mat[i][*it])
                    viz[i][*it]=1;
        }

    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(i!=j)
                if(!viz[i][j]){
                    cout<<"NO\n";
                    return 0;
                }
    cout<<"YES\n";
    return 0;
}