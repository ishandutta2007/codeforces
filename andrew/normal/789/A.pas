var
 DV:ARRAY[0..10000,0..10000]of longint;
 dvs:array[0..10000,0..10000]of ansistring;
 a,b:array[0..100000]of longint;
 s1,s2:array[0..10000]of ansistring;
 s:ansistring;
 c:char;
 sc,ch1,ch2,ch3,ch4,n,m,k,l,o,i,j,i1,j1,max,min,mj,mi:longint;
procedure swap(var a,b:longint);
var  c:longint;
begin
 c:=a;
 a:=b;
 b:=c;
end;
function comp(a,am:longint):boolean;
begin
 comp:=a<am;
end;
procedure sort(l,r:longint);
var m,i,j:longint;
begin
 m:=a[l+random(r-l+1)];
 i:=l;
 j:=r;
 repeat
  while comp(a[i],m)do inc(i);
  while comp(m,a[j])do dec(j);
  if i>j then break;
  swap(a[i],a[j]);
  inc(i); dec(j);
 until i>j;
 if i<r then sort(i,r);
 if l<j then sort(l,j);
end;
begin
 randomize;
 readln(n,k);
 for i:=1 to n do read(a[i]);
 for i:=1 to n do
 begin
  sc:=sc+a[i] div k;
  if a[i]mod k<>0 then inc(sc);
 end;
 writeln(sc div 2+sc mod 2);
end.