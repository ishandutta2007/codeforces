#include <iostream>
#include <string>

using namespace std;

string toate[8]={"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
int marime[8]={8,7,7,6,7,7,7,7};

bool match(string cine,string model)
{
    for(int i=0;i<model.size();i++)
        if(model[i]!='.')
            if(cine[i]!=model[i])
                return 0;
    return 1;
}

int main()
{
    int n;
    cin>>n;

    string model;
    cin>>model;

    for(int i=0;i<8;i++)
        if(n==marime[i])
            if(match(toate[i],model)){
                cout<<toate[i]<<'\n';
            }

    return 0;
}