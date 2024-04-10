#include <iostream>
int k,n,w;
int counter = 0;
using namespace std;

int main()
{
cin>>k>>n>>w;
for(int i = 1; i <= w; i++){
    counter+=k*i;
}
if(counter>n){
counter-=n;
cout<<counter;
}
else{
    cout<<0;
}

}