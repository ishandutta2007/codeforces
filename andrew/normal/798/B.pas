var

 s1,s2:ansistring;
 s,cops:array[1..50]of ansistring;
 a:array[0..1500]of longint;
 c:char;
 ans,mx,sc1,sc2,sc,i,j,q1,q2,n,k:longint;
procedure swap(var a,b:char);
var c:char;
begin
 c:=a;
 a:=b;
 b:=c;
end;
begin
 ans:=maxlongint;
 readln(n);
 for i:=1 to n do readln(s[i]);
for j:=1 to n do
begin
 mx:=0;
 for i:=1 to n do if i<>j then
 begin
  sc:=0;
  s1:=s[i];
  if s1=s[j] then continue;
  while(s1<>s[j]) do
  begin
   c:=s1[1];
   delete(s1,1,1);
   s1:=s1+c;
   inc(sc);
   if sc>=50 then begin writeln(-1); halt; end;
  end;
  inc(mx,sc);
 end;
 if mx<ans then ans:=mx;
end;
 writeln(ans);
 //writeln(-1);
end.