var
 x,y:array[0..100000]of longint;
 q:array[0..100000]of record
  pz:longint;
 end;
 a:array[1..1000,1..1000]of longint;
 j,n,r,q2,q1,i,m,ch,b,i1,j1,pp:longint;
procedure add(x,y:longint);
begin
 if a[x,y]<>0 then exit;
 a[x,y]:=r;
 q[q1].pz:=j;
 inc(q1);
end;
begin
 readln(n);
 for i:=1 to n do readln(x[i],y[i]);
 for i:=1 to n do if a[x[i],y[i]]=0 then
 begin
  inc(r);
  q1:=0;
  q2:=0;
  j:=i;
  add(x[i],y[i]);
  while q1<>q2 do with q[q2] do
  begin
   for j:=1 to n do if (pz<>j)and((x[j]=x[pz])or(y[j]=y[pz]))then add(x[j],y[j]);
   inc(q2);
  end;
 end;
 writeln(r-1);
end.