#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

int p(int b,int e)
{
    int res=1;
    while(e)
    {
        res*=b;
        e--;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    string s;
    for(int o=0;o<n;o++)
    {
        cin >> s;
        vector<string> v;
        string temp;
        temp+=s[0];
        for(int i=1;i<(int)s.size();i++)
        {
            if((isdigit(s[i])&&isalpha(s[i-1]))||(isalpha(s[i])&&isdigit(s[i-1])))
            {
                v.push_back(temp);
                temp=s[i];
            }
            else temp+=s[i];
        }
        v.push_back(temp);
        if(v.size()==4)
        {
            int r=stoi(v[1],nullptr,10);
            int c=stoi(v[3],nullptr,10);
            vector<int> decrypt;
            while(c)
            {
                decrypt.push_back((c-1)%26);
                c=(c-1)/26;
            }
            for(int i=(int)decrypt.size()-1;i>=0;i--)
            {
                cout << (char)('A'+decrypt[i]);
            }
            cout << r << endl;
        }
        else
        {
            int c=0;
            for(int i=0;i<(int)v[0].size();i++)
            {
                c+=(v[0][i]-'A'+1)*p(26,v[0].size()-i-1);
            }
            cout << "R" << v[1] << "C" << c << endl;
        }
    }
    return 0;
}