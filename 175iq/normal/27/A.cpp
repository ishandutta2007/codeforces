    #include <bits/stdc++.h>
    using namespace std;
    
    
    int main()
    {
        int n;
        cin>>n;
        
        int x;
        vector<bool> isp(3001,0);
        
        for(int i=0 ;i<n ;i++)
        {
            cin>>x;
            isp[x]=1;
        }
        
        int i;
        for(i=1; i<=3000; i++)
        {
            if(!isp[i])
            {
                break;
            }
        }
        
        cout<<i;
        return 0;
    }