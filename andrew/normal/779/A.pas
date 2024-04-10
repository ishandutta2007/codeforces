var
 a,b,c:array[1..10000]of longint;
 oc,oc1:array[1..5]of longint;
 sc,sc1,i,j,i1,j1,ch1,ch2,k,n,m:Longint;
procedure swap(var a,b:longint);
var c:longint;
begin
 c:=a;
 a:=b;
 b:=c;
end;

procedure sort(l,r:longint);
var i,j,m:longint;
begin
 i:=l;
 j:=r;
 m:=a[l+random(r-l+1)];
 repeat
  while a[i]<m do inc(i);
  while a[j]>m do dec(j);
  if i>j then break;
  swap(a[i],a[j]);
  inc(i);
  dec(j);
 until i>j;
 if i<r then sort(i,r);
 if l<j then sort(l,j);
end;

begin
 readln(n);
 for i:=1 to n do read(a[i]); readln;
 for i:=1 to n do read(b[i]);
 for i:=1 to n do inc(oc[a[i]]);
 for i:=1 to n do inc(oc1[b[i]]);

 for i:=1 to 5 do
 begin
 // writeln(oc[i],' ',oc1[i]);
  if oc[i]=oc1[i] then continue;
  ch1:=oc[i]+oc1[i];
  if ch1 mod 2=1 then begin writeln(-1); halt; end;
  ch1:=ch1 div 2;
  if oc[i]>ch1 then sc:=sc+abs(oc[i]-ch1);
  if oc1[i]>ch1 then sc1:=sc1+abs(oc1[i]-ch1);
 end;
// writeln(sc,' ',sc1);
 if sc<>sc1 then writeln(-1) else writeln(sc);
end.