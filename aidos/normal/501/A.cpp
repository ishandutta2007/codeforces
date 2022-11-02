#include <iostream>
int get(int a, int b){
int x = a - a/250 * b;
int y = a * 3/10;
if( x > y) return x;
return y;
}
int main(){
int a, b, c, d;
std::cin>>a >> b >> c >> d;
if(get(a, c) > get(b, d)) std::cout << "Misha";
else if(get(a, c) < get(b, d)) std::cout << "Vasya";
else std::cout << "Tie";

}