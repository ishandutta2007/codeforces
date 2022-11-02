program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils,
  Math;

type int=integer;
     boat=array[0..100100,1..3]of int;
     data=array[0..100100,1..3]of int;
var a,b,g:boat;
    ans:array[0..100100]of boolean;
    n,v,kans,sumans,x,y:int;
    c:data;

procedure swap(var a,b:int);
 var c:int;
begin
 c:=a;
 a:=b;
 b:=c
end;

procedure qsort(l,r:int;var a:boat);
 var i,j,x:int;
begin
 i:=l;
 j:=r;
 x:=a[l+random(r-l+1),1];
 while i<=j do begin
  while x>a[i,1] do inc(i);
  while x<a[j,1] do dec(j);
  if i<=j then begin
   swap(a[i,1],a[j,1]);
   swap(a[i,2],a[j,2]);
   inc(i);
   dec(j)
  end
 end;
 if i<r then qsort(i,r,a);
 if j>l then qsort(l,j,a)
end;

procedure qsortc(l,r:int);
 var i,j,x:int;
begin
 i:=l;
 j:=r;
 x:=c[l+random(r-l+1),1];
 while i<=j do begin
  while x>c[i,1] do inc(i);
  while x<c[j,1] do dec(j);
  if i<=j then begin
   swap(c[i,1],c[j,1]);
   swap(c[i,2],c[j,2]);
   swap(c[i,3],c[j,3]);
   inc(i);
   dec(j)
  end
 end;
 if i<r then qsortc(i,r);
 if j>l then qsortc(l,j)
end;

procedure readdata;
 var t,p,i:int;
begin
 readln(n,v);
 x:=0;
 y:=0;
 for i:=1 to n do begin
  readln(t,p);
  if t=1 then begin
   inc(x);
   a[x,1]:=p;
   a[x,2]:=i
  end
  else begin
        inc(y);
        b[y,1]:=p;
        b[y,2]:=i
       end
 end
end;

procedure solve;
 var i,max,j,z:int;
begin
 sumans:=0;
 for i:=1 to n do ans[i]:=false;
 if v mod 2<>0 then begin
  max:=1;
  for i:=2 to x do
   if a[i,1]>a[max,1] then max:=i;
  sumans:=a[max,1];
  ans[a[max,2]]:=true;
  dec(v);
  swap(a[max,1],a[x,1]);
  swap(a[max,2],a[x,2]);
  dec(x)
 end;
 if v=0 then exit;
 qsort(1,x,a);
 qsort(1,y,b);
 for i:=1 to y do begin
  c[i,1]:=b[i,1];
  c[i,2]:=b[i,2];
  c[i,3]:=-1
 end;
 z:=y;
 if x mod 2<>0 then begin
  inc(z);
  c[z,1]:=a[1,1];
  c[z,2]:=a[1,2];
  c[z,3]:=-1;
  for i:=1 to x-1 do begin
   swap(a[i,1],a[i+1,1]);
   swap(a[i,2],a[i+1,2])
  end;
  dec(x)
 end;
 i:=x;
 while i>0 do begin
  inc(z);
  c[z,1]:=a[i,1]+a[i-1,1];
  c[z,2]:=a[i,2];
  c[z,3]:=a[i-1,2];
  dec(i,2)
 end;
 qsortc(1,z);
 while (v>0)and(z>0)do begin
  inc(sumans,c[z,1]);
  ans[c[z,2]]:=true;
  if c[z,3]<>-1 then ans[c[z,3]]:=true;
  dec(v,2);
  dec(z)
 end;
 {swapboat(a,b);
 i:=x;
 j:=0;
 z:=0;
 b[0,1]:=0;
 b[0,2]:=0;
 while i>0 do begin
  inc(j);
  c[j,1]:=b[i,2];
  c[j,2]:=b[i-1,2];
  inc(z);
  a[z+y,1]:=b[i,1]+b[i-1,1];
  a[z+y,2]:=j;
  c[j,3]:=z+y;
  dec(i,2)
 end;

 for i:=1 to y do begin
  a[i+x,1]:=b[i,1];
  a[i+x,2]:=b[i,2]
 end;
 n:=y+z;
 qsort(1,n,a);
 while (n>0)and(v>0)do begin
  if c[a[n,2],3]=n then begin
   inc(kans);
   ans[kans]:=c[a[n,2],1];
   inc(kans);
   ans[kans]:=c[a[n,2],2]
  end
  else begin
        inc(kans);
        ans[kans]:=a[n,2]
       end;
  inc(sumans,a[n,1]);
  dec(n);
  dec(v,2)
 end }
end;

procedure writedata;
 var i:int;
begin
 writeln(sumans);
 for i:=1 to n do
  if ans[i] then write(i,' ')
end;

begin
 //reset(input,'input.txt');
 //rewrite(output,'output.txt');
 randomize;
 readdata;
 solve;
 writedata
end.