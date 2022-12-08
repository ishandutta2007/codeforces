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


		#define rpt (  i  ,   l  ,   r  )   for   (  int i=l;i  <= r;i ++  )

	#define rpd   (  i ,  r ,  l  )   for ( int i=r;i   >=  l;i -- )


			int sg [   99 ]  =

		{  0 ,  1 , 1   , 2 ,  2  , 2  , 3  , 3   ,  3 ,  3 , 4  ,  4  ,  4  ,   4  ,   4 ,  5   ,   5  ,  5   ,  5  ,  5  ,   5  , 6 ,   6 ,   6  ,   6  ,  6 , 6 ,  6  , 7  ,   7 ,  7  , 7 , 7   , 7  ,  7 , 7  , 8  ,   8  ,   8  , 8 , 8  ,


			8  ,   8  , 8 , 8   ,  9   , 9 ,  9 ,   9 ,   9   ,   9 , 9  ,  9 , 9 , 9  ,   10 ,  10  ,  10 ,   10   ,  10 ,   10 } ;

		int main  (  )



		{



		int n ,  x   ,   s=0;


			scanf ( "%d"   ,  &n   ) ;



	while  (  n --   )


		{



		scanf (  "%d"  ,   &x ) ;


		s   ^=  sg [  x ]   ;



		 }

	printf ( s?"NO":"YES" )   ;


			  }