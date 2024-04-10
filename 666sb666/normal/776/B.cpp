			#include<cstdio>

			#include<cstring>

		#include<cmath>

	#include<cstdlib>

			#include<iostream>

			#include<algorithm>



	#include<string>


	#include<vector>



		#include<queue>


	#include<set>

		#include<map>


			using namespace std;


		int vis  [ 100005  ]  , p   [  100005 ]  ,  ps , n;


		int main (   )

	{



	scanf   ( "%d"  , &n )  ; if   (  n  ==  1 )

		{ printf   ( "1\n1\n" )   ;return 0;   }



		if  (   n  ==   2  )


		{   printf  ( "1\n1 1\n"  )   ;return 0; } ++   n; 

		for    (  int i=2;i <=  n;i  ++  )  if  (   !vis [   i ]  )



			for  (   int j=i+i;j   <=  n;j += i   )   vis  [ j   ] =1;

			printf  (  "2\n"  )  ;


	for    (  int i=2;i  <= n;i  ++  )   if    (  !vis   [ i ] )  printf ( "1 "   ) ;else printf   (  "2 " )  ;

	 }