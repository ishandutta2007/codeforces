var
 a:array[1..1000000]of longint;
 b,b1:array[1..500000]of longint;
 m,kst,n,k,i,j,sc,ch1,ch2,ch3:longint;
procedure swap(var a,b:longint);
var c:longint;
begin
 c:=a;
 a:=b;
 b:=c;
end;
begin
 readln(n,m,k);
 kst:=1;
 for i:=1 to m do
 begin
  read(ch1);
  a[ch1]:=1;
 end;
 readln;
 if a[1]=1 then begin writeln(1); halt; end;
 for i:=1 to k do
 begin
  readln(b[i],b1[i]);
  if(b[i]=kst)then
  begin
   if a[b1[i]]=1 then begin writeln(b1[i]); halt; end;
   kst:=b1[i];
   continue;
  end;
  if(b1[i]=kst)then
  begin
   if a[b[i]]=1 then begin writeln(b[i]); halt; end;
   kst:=b[i];
   continue;
  end;
 end;
 writeln(kst);
end.