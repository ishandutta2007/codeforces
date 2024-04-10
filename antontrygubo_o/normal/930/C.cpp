#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;
    int cnt[m] = {0};
    int a, b;
    
    int leftend[m] = {0};
    int rightend[m] = {0};
    
    for (int i = 0; i<n; i++)
    {
        cin>>a>>b;
        a--; b--;
        leftend[a]++;
        rightend[b]++;
    }
    
    cnt[0] = leftend[0];
    for (int i = 1; i<m; i++)
    {
        cnt[i] = cnt[i-1] + leftend[i] - rightend[i-1];
    }
    
    //for (int i = 0; i<m; i++) cnt[i] = 9-i;
    
    //for (int i = 0; i<m; i++) cout<<cnt[i]<<' ';
    
    int bestup[m];//   cnt[i];
    vector<int> leasti;//       i
    leasti.push_back(0);
    
    for (int i = 1; i<=m; i++)	leasti.push_back(1000000);
    
	bestup[0] = 1;
	leasti[0] = cnt[0];
	//cout<<endl;
    for (int i = 0; i<m; i++)
    {
        int j = int (upper_bound(leasti.begin(), leasti.end(), cnt[i])-leasti.begin());
        if ((leasti[j-1]<=cnt[i])&&(cnt[i]<leasti[j])) leasti[j] = cnt[i];
        bestup[i] = j-1;
    }
    //cout<<"leasti"<<' '; for (int i = 0; i<m; i++) cout<<leasti[i]<<' '; 
    //cout<<endl;
    //cout<<"bestup"<<' '; for (int i = 0; i<m; i++) cout<<bestup[i]<<' ';
    
    
    for (int i = 0; i<m/2; i++) swap(cnt[i], cnt[m-1-i]);
    
    
    
   // cout<<endl<<endl;
    //for (int i = 0; i<m; i++) cout<<cnt[i]<<' ';   
   // cout<<endl<<endl;   
    
    
    
    
    
    
    int bestuj[m];//   cnt[i];
    vector<int> leastj;// ,      i
    leastj.push_back(1);
    
    for (int i = 1; i<=m; i++)	leastj.push_back(1000000);
    
	bestuj[0] = 1;
	leastj[0] = cnt[0];
	//cout<<endl;
    for (int i = 0; i<m; i++)
    {
        int j = int (upper_bound(leastj.begin(), leastj.end(), cnt[i])-leastj.begin());
        if ((leastj[j-1]<=cnt[i])&&(cnt[i]<leastj[j])) leastj[j] = cnt[i];
        bestuj[i] = j-1;
    }
    
    //for (int i = 0; i<m; i++) cout<<bestuj[i]<<' ';
    int maxx = 0;
    //cout<<endl;
    
    //for (int i = 0; i<m; i++) cout<<leastj[i]<<' '; cout<<endl;
    for (int i = 0; i<m; i++) maxx = max(maxx, bestup[i]+bestuj[m-1-i]+1);
    cout<<maxx;

}