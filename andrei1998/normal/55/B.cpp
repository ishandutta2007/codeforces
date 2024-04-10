#include <iostream>
#include <vector>

#define lint long long int
using namespace std;

char op[4];
lint minim=2000000000005;

void backtr(int poz,vector<lint> toate){
    if(poz==4){
        if(toate.front()<minim)
            minim=toate.front();
        return;
    }

    vector<lint> nou;
    for(int i=0;i<toate.size();i++)
        for(int j=i+1;j<toate.size();j++){
            nou.clear();

            if(op[poz]=='+')
                nou.push_back(toate[i]+toate[j]);
            else
                nou.push_back(toate[i]*toate[j]);

            for(int k=0;k<toate.size();k++)
                if(k!=i && k!=j)
                    nou.push_back(toate[k]);
            backtr(poz+1,nou);
        }
}

int main()
{
    vector<lint> init;
    int a,b,c,d;

    cin>>a>>b>>c>>d;

    init.push_back(a);
    init.push_back(b);
    init.push_back(c);
    init.push_back(d);

    for(int i=1;i<=3;i++)
        cin>>op[i];

    backtr(1,init);

    cout<<minim<<'\n';
    return 0;
}