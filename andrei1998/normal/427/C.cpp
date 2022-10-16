#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

vector<int> graf[100005];
vector<int> invgraf[100005];
int term[100005];
int cate[100005];
int minim[100005];
int pret[100005];

#define mod 1000000007
bitset<100005> viz1;
bitset<100005> viz2;
int t;

void dfs1(int nod)
{
    vector<int>::iterator it;
    for(it=invgraf[nod].begin();it!=invgraf[nod].end();it++)
        if(!viz1[*it])
        {
            viz1[*it]=1;
            dfs1(*it);
        }

    term[++t]=nod;
}

int j;
void dfs2(int nod)
{
    vector<int>::iterator it;
    for(it=graf[nod].begin();it!=graf[nod].end();it++)
        if(!viz2[*it])
        {
            if(pret[*it]<minim[j])
            {
                minim[j]=pret[*it];
                cate[j]=1;
            }
            else if(pret[*it]==minim[j])
                cate[j]++;

            viz2[*it]=1;
            dfs2(*it);
        }
}

int main()
{
    int n,m,a,b;
    cin>>n;

    int i;
    for(i=1;i<=n;i++)
        cin>>pret[i];
    cin>>m;

    while(m--)
    {
        cin>>a>>b;
        graf[a].push_back(b);
        invgraf[b].push_back(a);
    }

    for(i=1;i<=n;i++)
        if(!viz1[i])
        {
            viz1[i]=1;
            dfs1(i);
        }

    long long int ans1=0;
    long long int ans2=1;

    j=1;
    for(i=n;i>=1;i--)
    {
        if(!viz2[term[i]])
        {
            viz2[term[i]]=1;
            minim[j]=pret[term[i]];
            cate[j]=1;

            dfs2(term[i]);
            ans1+=minim[j];

            ans2=(1ll*cate[j]*ans2)%mod;

            j++;
        }
    }
    cout<<ans1<<' '<<ans2<<'\n';

    return 0;
}