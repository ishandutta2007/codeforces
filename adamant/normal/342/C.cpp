#include <iostream>
main(){float r,h;
std::cin>>r>>h;
int d=h/r+0.5;
std::cout<<(int)((h/r+1-d)*1.154701)+d*2;}