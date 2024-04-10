#include<bits/stdc++.h>
using namespace std;

struct ip
{
    string name;
    string number;
};

vector<ip> servers;

int main()
{
    int n, m;
    cin>>n>>m;
    for (int i = 0; i<n; i++)
    {
        ip temp;
        cin>>temp.name>>temp.number;
        servers.push_back(temp);
    }
    
   // for (int i = 0; i<n; i++) cout<<servers[i].name<<' '<<servers[i].number<<endl;
    
    for (int i = 0; i<m; i++)
    {
        ip temp;
        cin>>temp.name>>temp.number;
        for (int j = 0; j<servers.size(); j++) 
        {
            if (temp.number.length()==servers[j].number.length()+1)
            {
                bool t = true;
                for (int h = 0; h<servers[j].number.length(); h++) if (servers[j].number[h]!=temp.number[h]) t = false;
                if (t) cout<<temp.name<<' '<<temp.number<<' '<<"#"<<servers[j].name<<endl;
            }
            
        }
    }



}