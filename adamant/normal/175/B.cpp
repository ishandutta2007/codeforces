#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    
    int N;
    
    cin>>N;
    
    vector<string> all;
    
    vector<int> sum;
    
    for(int i=0;i<N;i++)
    {
            string tmp;
            cin>>tmp;
            bool newe=true;
            int in;
            for(int j=0;j<all.size();j++)
            {
                    if(all[j]==tmp)
                    {
                                   in=j;
                                   newe=false;
                    }
            }
            
            int rez;
            cin>>rez;
            if(newe)
            {
            sum.push_back(rez);
            all.push_back(tmp);
            }
            else
            if(rez>sum[in])
            sum[in]=rez;
            
    }
    
    cout<<all.size()<<endl;
    
    int**ans=new int*[all.size()];
    
    for(int i=0;i<all.size();i++)
    {
            ans[i]=new int[2];
            
            ans[i][1]=0;
            for(int j=0;j<all.size();j++)
            {
                    if(sum[j]>sum[i])
                    ans[i][1]++;
            }
            //cout<<"sum:"<<sum[i]<<"ans[i][1]:"<<ans[i][1]<<endl;
            if( ( double(all.size()-ans[i][1]) / double(all.size()) )*100 >= 99 )
            ans[i][0]=5;
            else if( ( double(all.size()-ans[i][1]) / double(all.size()) )*100 >= 90 )
            ans[i][0]=4;
            else if( ( double(all.size()-ans[i][1]) / double(all.size()) )*100 >= 80 )
            ans[i][0]=3;
            else if( ( double(all.size()-ans[i][1]) / double(all.size()) )*100 >= 50 )
            ans[i][0]=2;
            else if( ( double(all.size()-ans[i][1]) / double(all.size()) )*100 < 50 )
            ans[i][0]=1;
            cout<<all[i]<<' ';
            if(ans[i][0]==5)
            cout<<"pro"<<endl;
            if(ans[i][0]==4)
            cout<<"hardcore"<<endl;
            if(ans[i][0]==3)
            cout<<"average"<<endl;
            if(ans[i][0]==2)
            cout<<"random"<<endl;
            if(ans[i][0]==1)
            cout<<"noob"<<endl;
            
    }
    return EXIT_SUCCESS;
}