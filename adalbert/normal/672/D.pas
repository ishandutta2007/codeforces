uses math;
var i,n:longint;
d,s,pos1,pos2,k:int64;
a:array[1..1000000] of longint;

procedure bsmax(l,r:int64);
    begin
    while r-l>1 do
       begin
       s:=0;
       d:=(l+r) div 2;
       for i:=1 to n do if a[i]>d then
       s:=s+a[i]-d;
       if s>k then l:=d else r:=d;
       end;
    pos1:=l;
    end;
procedure bsmin(l,r:int64);
    begin
    while r-l>1 do
       begin
       s:=0;
       d:=(l+r) div 2;
       for i:=1 to n do if a[i]<d then
       s:=s+d-a[i];

       if s>k then r:=d else l:=d;
       end;

    pos2:=l;
    end;






begin
read(n,k);
for i:=1 to n do read(a[i]);
bsmax(0,10000000000);
bsmin(0,10000000000);
pos1:=pos1+1;

s:=0;
for i:=1 to n do if a[i]>pos1 then s:=s+a[i]-pos1;

if s>k then dec(pos1);
s:=0;
//writeln(pos2);
inc(pos2);
for i:=1 to n do if a[i]<pos2 then s:=s-a[i]+pos2;
if s>k then dec(pos2);
//writeln(s,'*');
s:=0;
for i:=1 to n do s:=s+a[i];
//writeln(pos1,' ',pos2);
if (s mod n)<>0 then s:=1 else s:=0;
writeln(max(pos1-pos2,s));
end.