// Example program
#include <iostream>
#include <string>

int main()
{
  std::string first_s, second_s;
  int first_i=-1, second_i=-1;
  std::string arr[]={"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
  std::cin >> first_s;
  std::cin >> second_s;
  for(int i=0;i<7;i++){
      if (first_s.compare(arr[i]) == 0){
        first_i=i;
      }
      if (second_s.compare(arr[i]) == 0){
        second_i=i;
      }
  }
  if(second_i==-1||first_i==-1){
      std::cout << "NO\n";
  } else if(first_i==second_i) {
      std::cout << "YES\n";
  } else if((first_i+2)%7==second_i) {
      std::cout << "YES\n";
  } else if((first_i+3)%7==second_i) {
      std::cout << "YES\n";
  } else {
      std::cout << "NO\n";
  }
}