program code4;

{$APPTYPE CONSOLE}
{$minstacksize 64000000}
uses
  SysUtils,Math;
type int=integer;
     ext=extended;
     bool=boolean;
     segm=record
      b:bool;
      k:int;
      p:int
     end;
var n,m,ans:int;
    a:array[-1..4000]of segm;
    answer:array[-1..2200]of int;

procedure swap(var a,b:int);
 var c:int;
begin
 c:=a;
 a:=b;
 b:=c
end;

procedure swapsegm(var a,b:segm);
 var c:segm;
begin
 c:=a;
 a:=b;
 b:=c
end;

function comp(x,y:int):bool;
begin
 if x=y then begin
  comp:=false;
  exit
 end;
 if (a[y].p>a[x].p)or((a[y].p=a[x].p)and a[x].b and(x<>y))then comp:=true
  else comp:=false
end;

procedure qsort(l,r:int);
 var i,j,x:int;
begin
 i:=l;
 j:=r;
 x:=(l+r)div 2;
 while i<=j do begin
  while comp(i,x) do inc(i);
  while comp(x,j) do dec(j);
  if i<=j then begin
   swapsegm(a[i],a[j]);
   inc(i);
   dec(j)
  end;
 end;
 if i<r then qsort(i,r);
 if j>l then qsort(l,j)
end;

procedure readdata;
 var i,x,y:int;
begin
 readln(n);
 m:=0;
 for i:=1 to n do begin
  readln(x,y);
  if x>y then swap(x,y);
  inc(m);
  a[m].p:=x;
  a[m].b:=true;
  a[m].k:=i;
  inc(m);
  a[m].p:=y;
  a[m].b:=false;
  a[m].k:=i
 end
end;

procedure solve;
 var b:array[-1..1100]of bool;
     q:array[-1..5000]of int;
     i,j,z:int;
     f:bool;
begin
 ans:=0;
 //qsort(1,m);
 f:=true;
 for i:=1 to m do begin
  if not f then break;
  f:=false;
  for j:=1 to m-1 do
   if (a[j].p>a[j+1].p)or((a[j].p=a[j+1].p)and a[j+1].b) then begin
                              swapsegm(a[j],a[j+1]);
                              f:=true;
   end;
 end;
 for i:=0 to n do
  b[i]:=false;
 z:=0;

 for i:=1 to m do
  if a[i].b then begin
   inc(z);
   q[z]:=a[i].k;
  end
  else
   if(not b[a[i].k])and(not a[i].b)then begin
                                         inc(ans);
                                         answer[ans]:=a[i].p;
                                         b[a[i].k]:=true;
                                         for j:=1 to z do
                                          b[q[j]]:=true;
                                         z:=0
                                        end
end;

procedure writedata;
 var i:int;
begin
 writeln(ans);
 for i:=1 to ans do
  write(answer[i],' ');
end;

begin
 {$IFNDEF ONLINE_JUDGE}
 reset(input,'input.txt');
 rewrite(output,'output.txt');
 {$ENDIF}
 readdata;
 solve;
 writedata
end.