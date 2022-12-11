var b,c:array[1..5000]of longint;
    a,n,m,i,f,g,k,l,x,y:longint;
    z:extended;
begin
 a:=0;
 read(n);for i:=1 to n do begin read(x);if x>a then a:=x;end;
 read(m);for i:=1 to m do read(b[i]);
 read(k);for i:=1 to k do read(c[i]);
 readln(x,y);
 z:=0;
 for f:=1 to m do
  for g:=1 to k do
   if (sqrt(((y/x)*sqr(a)*b[f])/((y/x)*b[f]+c[g]))>z)and(sqrt(((y/x)*sqr(a)*b[f])/((y/x)*b[f]+c[g]))<a) then z:=sqrt(((y/x)*sqr(a)*b[f])/((y/x)*b[f]+c[g]));
 writeln(z:1:12);
end.