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

		#define gc getchar  ( )


			const int N=200100;



		int n  ,  m , fa  [   N   ]  , v  [  N  ]  , flc [ N  ] [  3  ]  ,  p   [  N ]   ;

			void r  (  int &x )

		{

		int ch=gc; x=0; while  (   ch<'0'||ch>'9'   )    ch=gc;


			while   (  ch  >= '0' && ch <= '9' )  x=x*10+ch-'0'  , ch=gc;


		 }



		int find (  int x  )

		{



	if    (   x ==  fa [  x  ]   )    return x;

		int f=fa  [  x ]   ; fa   [   x  ] =find ( fa   [ x   ]  )  ; v   [  x   ]  ^= v [ f  ]   ;

			return fa  [ x ]  ;


		  }

		int merge  ( int x ,  int y   ,  int p   )


		{

		int fx=find  (   x  ) ,  fy=find   (  y  )  ; //printf (  "%d %d %d\n" ,  x , y ,   p  )   ;

	if    (  fx   ==   fy )  return v [  x ] ^v [  y ]  ^p^1;


			fa [ fx  ]  =fy; v   [   fx  ] ^= v   [  x ]  ^v [  y   ]  ^p;

			return 1;


		   }

			int main ( )

			{

		r ( n ) ; r  (   m  )  ;


	for   (  int i=1; i   <=  n; i  ++  )   r  (  p   [   i   ] ) ;


		for    ( int i=1  ,  x; i <=  m; i  ++   )


		{


		r ( x  )  ; 


		for  (  int j=1  , t; j  <= x; j  ++  )  r  ( t ) ,  flc   [ t ]   [  ++  flc [ t ] [   0  ] ]   =i;

			 }



		int pd=1;


		for   (  int i=1; i   <=  m; i ++ )  fa  [   i ]  =i;


	for  ( int i=1; i  <=  n; i  ++   )

	if ( !merge  (  flc  [ i  ]  [  1 ]  ,   flc  [ i   ] [   2 ]  , p [ i  ]  ^1  )  )


		{

	pd=0; break;


		   }

	if   ( !pd   )  printf   (   "NO\n"   ) ;


		else printf (  "YES\n" )  ;



		return 0;

	 }