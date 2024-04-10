var
 a,b,c:array[0..1001,0..1001]of longint;
 ch1,ch2,ch3,su1,su2,i1,j1,pz,sc,i,w,d,k,l,j,m,n:longint;
procedure proverka;
begin
 if b[i,j-1]>0 then inc(sc);
 if b[i,m]-b[i,j-1]>0 then inc(sc);
 if c[i-1,j]>0 then inc(sc);
 if c[n,j]-c[i-1,j]>0 then inc(sc);
end;
begin
 readln(n,m);
 for i:=1 to n do
 begin
  for j:=1 to m do read(a[i,j]);
  readln;
 end;
 for i:=1 to n do
 begin
  su1:=0;
  for j:=1 to m do begin if a[i,j]=1 then inc(su1);b[i,j]:=su1; end;
 end;
 for i:=1 to m do
 begin
  su1:=0;
  //writeln;
  for j:=1 to n do
  begin
   if a[j,i]=1 then inc(su1);
   c[j,i]:=su1;
   //write(c[i,j]);
  end;
 end;

 for i:=1 to n do
 for j:=1 to m do if a[i,j]=0 then
 begin
  proverka;
 end;
 writeln(sc);
end.