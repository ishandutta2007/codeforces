#include<bits/stdc++.h>
using namespace std;

bool school[2000][2000] = {0};

int main()
{
    char f;
    int n, m, k;
    cin>>n>>m>>k;
    int summ = 0;
    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<m; j++)
        {cin>>f;
        if (f=='.') {school[i][j]=1; summ++;}}
    }
    

if (k==1)
{
    cout<<summ; return 0;
}
int number = 0;  

for (int i = 0; i<n; i++)
{
     int length = 1;
     int where = 0;
     while (where<m)
     {
         if (school[i][where]==0) where++;
         else {length = 0;
         while ((where<m)&&(school[i][where]==1))
         {
             length++; where++;
         }
         if (length>=k) number+=length+1-k;}
     }
     
}
    
   for (int j = 0; j<m; j++)
{
     int length = 1;
     int where = 0;
     while (where<n)
     {
         if (school[where][j]==0) where++;
         else {length = 0;
         while ((where<n)&&(school[where][j]==1))
         {
             length++; where++;
         }
         if (length>=k) number+=length+1-k;}
     }
     
} 
    cout<<number;
    
}