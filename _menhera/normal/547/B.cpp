#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
int A[200200];
pair<int, int> P[200200];
int ans[200200];
set<int> S;
multiset<int> MS;
int main()
{
    int N;
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
    {
        ans[i]=1987654321;
        scanf("%d",A+i);
        P[i]=make_pair(A[i],i);
    }
    sort(P+1,P+N+1);
    S.insert(0);
    S.insert(N+1);
    MS.insert(N+1);
    for(int i=1;i<=N;i++)
    {
        set<int>::iterator it=S.upper_bound(P[i].second);
        set<int>::iterator it2=it--;
        //printf("<%d %d>",*it2,*it);
        MS.erase(MS.find((*it2)-(*it)));
        MS.insert((*it2)-P[i].second);
        MS.insert(P[i].second-(*it));
        S.insert(P[i].second);
        multiset<int>::iterator it3=MS.end();
        it3--;
        //printf("%d ", *it3);
        ans[*it3]=min(ans[*it3],P[i].first);
    }
    for(int i=2;i<=N;i++)
        ans[i]=min(ans[i-1],ans[i]);
    for(int i=1;i<=N;i++)
        printf("%d ",ans[i]);
    return 0;
}