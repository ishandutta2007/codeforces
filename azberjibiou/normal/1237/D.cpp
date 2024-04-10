#include <bits/stdc++.h>
using namespace std;
int N, A[303030], ans[301010];
vector <int> sma;
stack <int> big;
int main()
{
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        cin >> A[i];
        A[i+N]=A[i+2*N]=A[i];
    }
    sma.push_back(-1);
    for(int i=3*N;i>=1;i--)
    {
        while(!big.empty() && A[big.top()]<=A[i])
            big.pop();
        while(sma.back()!=-1 && A[sma.back()]>=A[i])
            sma.pop_back();
        int low=0, high=(int)sma.size()-1;
        int cnt=0;
        while(low<high)
        {
            int mid = (low+high+1)/2;
            //printf("low=%d, high=%d, sma[%d]=%d\n", low, high, mid, sma[mid]);
            if(A[sma[mid]]*2<A[i])
                low=mid;
            else
                high=mid-1;
            cnt++;
        }
        int small= (low==0) ? -1 : sma[low];
        int bigger= (big.empty()) ? -1 : big.top();
        //printf("sma=%d, big=%d\n", small, bigger);
        if(small!=-1 && bigger!=-1)
        {
            if(small<bigger)
                ans[i]=small-i;
            else
            {
                if(ans[bigger]!=-1)
                ans[i]=ans[bigger]+bigger-i;
                else
                    ans[i]=-1;
            }

        }
        else if(small==-1 && bigger!=-1)
        {
            if(ans[bigger]!=-1)
                ans[i]=ans[bigger]+bigger-i;
            else
                ans[i]=-1;
        }

        else if(small!=-1 && bigger==-1)
        {
            ans[i]=small-i;
        }
        else
            ans[i]=-1;
        big.push(i);
        sma.push_back(i);
    }
    for(int i=1;i<=N;i++)
        cout << ans[i] << " ";
}