#include <iostream>
#include <algorithm>

#define lint long long int
using namespace std;

lint det(lint a,lint b,int bit){
    if(!bit){
        if(a&1)
            return a;
        if(b&1)
            return b;
        return a;
    }

    if(a&(1ll<<bit))
        return det(a,b,bit-1);
    if(!(b&(1ll<<bit)))
        return det(a,b,bit-1);

    if((b&((1ll<<(bit+1))-1))==((1ll<<(bit+1))-1))
        return b;
    return ((a&(~((1ll<<bit)-1)))|((1ll<<bit)-1));
}

int main()
{
    int n=0;
    cin>>n;

    lint a=0,b=0;
    while(n--){
        cin>>a>>b;

        cout<<det(a,b,60)<<'\n';
    }

    return 0;
}