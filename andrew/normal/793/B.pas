var
 c:char;        
 a,b:array[0..1000,0..1000]of longint;
 x1,x2,y1,y2,n,m,i,j,q1,q2,sc,k:longint;
 q:array[0..100000]of record
  pp,y,x,dv:longint;
 end;
procedure add(y,x,pp,dv:longint);
begin
 if(y<1)or(x<1)or(y>n)or(x>m)or(b[y,x]=1)then exit;
 if pp>2 then exit;
 if pp>a[y,x] then exit;
 a[y,x]:=pp;
 q[q1].x:=x;
 q[q1].y:=y;
 q[q1].pp:=pp;
 q[q1].dv:=dv;
 inc(q1);
 if q1=100000 then q1:=0;
end;
begin
 readln(n,m);
 for i:=1 to n do
 begin
  for j:=1 to m do
  begin
   read(c);
   if c='S' then begin y1:=i; x1:=j; continue; end;
   if c='T' then begin y2:=i; x2:=j; continue; end;
   if c='*' then b[i,j]:=1;
  end;
  readln;
 end;
 for i:=1 to n do
  for j:=1 to m do a[i,j]:=maxlongint;
  add(y1,x1,0,5);
  while q1<>q2 do with q[q2] do
  begin
   if dv=1 then
   begin
    add(y+1,x,pp,1);
    add(y-1,x,pp+1,3);
    add(y,x+1,pp+1,2);
    add(y,x-1,pp+1,4);
   end;
   if dv=2 then
   begin
    add(y+1,x,pp+1,1);
    add(y-1,x,pp+1,3);
    add(y,x+1,pp,2);
    add(y,x-1,pp+1,4);
   end;
   if dv=3 then
   begin
    add(y+1,x,pp+1,1);
    add(y-1,x,pp,3);
    add(y,x+1,pp+1,2);
    add(y,x-1,pp+1,4);
   end;
   if dv=4 then
   begin
    add(y+1,x,pp+1,1);
    add(y-1,x,pp+1,3);
    add(y,x+1,pp+1,2);
    add(y,x-1,pp,4);
   end;
   if dv=5 then
   begin
    add(y+1,x,pp,1);
    add(y-1,x,pp,3);
    add(y,x+1,pp,2);
    add(y,x-1,pp,4);
   end;
   inc(q2);
   if q2=100000 then q2:=0;
  end;
 
 if(a[y2,x2]>2)or(a[y2,x2]=maxlongint)then writeln('NO')else writeln('Yes');
end.