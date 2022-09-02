#include<iostream>

using namespace std;

int main()
{
int V1, V2, V3, Vm;
cin>>V1>>V2>>V3>>Vm;
int Vmin = max(V3, Vm);
int Vmid = 2*V2;
int Vmax = 2*V1;
if( (Vmin<=2*V3)&&(Vmin<=2*Vm)&&(Vmid>2*Vm)) cout<<Vmax<<endl<<Vmid<<endl<<Vmin;
else cout<<-1;

}