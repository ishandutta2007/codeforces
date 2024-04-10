var
 q:array[0..100000]of record
  vis,pz:longint;
 end;
 a,l:array[0..1000]of longint;
 i1,j1,q1,q2,k,n,i,j,o,m:longint;
 ch:char;
procedure add(p:longint);
begin
 if (p<1)or(p>n)or(a[p]<>0)then exit;
 a[p]:=1;
 q[q1].pz:=p;
 inc(q1);
end;
begin
 readln(n,k);
 for i:=1 to n do
 begin
  read(ch);
  if ch='#'then a[i]:=1;
  if ch='G'then i1:=i;
  if ch='T'then j1:=i;
 end;
 add(i1);
 while q1<>q2 do with q[q2]do
 begin
  add(pz+k);
  add(pz-k);
  if a[j1]<>0then break;
  inc(q2);
 end;
 if a[j1]<>0 then writeln('Yes')else writeln('No');
end.