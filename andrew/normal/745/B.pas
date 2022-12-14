const
 maxQ=2500000;

var
 a:array[0..501,0..501]of longint;
 q:array[0..maxQ]of record
  y,x:longint;
 end;
 c:char;
 x1,x2,x3,x4,y1,y2,y3,y4,sc,sc1,sc2,r1,q1,q2,i,j,m,n,r:longint;

procedure add(y,x:longint);
begin
 if (y<1)or(y>n)or(x<1)or(x>m)or(a[y,x]<>1) then exit;

 a[y,x]:=r;
 q[q1].y:=y;
 q[q1].x:=x;
 inc(q1);
end;
begin
 readln(n,m);
 for i:=1 to n do
 begin
  for j:=1 to m do begin read(c); if c='X' then a[i,j]:=1; end;
  readln;
 end;

 r:=1;
 for i:=1 to n do
  for j:=1 to m do
   if a[i,j]=1 then
   begin
    y1:=i;
    x1:=j;
    inc(r);
    q1:=0;
    q2:=0;
    add(i,j);
    while q1<>q2 do with q[q2] do
    begin
     add(y-1,x);
     add(y+1,x);
     add(y,x-1);
     add(y,x+1);
     if(a[y-1,x]<>r)and(a[y,x+1]<>r)then begin x2:=x; y2:=y; end;
     if(a[y+1,x]<>r)and(a[y,x-1]<>r)then begin x3:=x; y3:=y; end;
     if(a[y+1,x]<>r)and(a[y,x+1]<>r)then begin x4:=x; y4:=y; end;
     inc(q2);
    end;
    sc:=x2-x1+1;
    if sc=0 then sc:=1;
    sc2:=y3-y1+1;
    if sc2=0 then sc2:=1;
    sc:=sc*sc2;
    if (q2=sc)and(y1=y2)and(y3=y4)and(x1=x3)and(x2=x4)then inc(r1);
   end;
  if (r-1)-r1=0 then writeln('YES')else writeln('NO');
end.