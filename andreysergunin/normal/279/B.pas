var i:longint;
    max,n,t,l,r,k:int64;
    a,b,c:array[0..100000] of int64;
begin
read (n,t);
for i:=1 to n do read (a[i]);
b[0]:=0;
for i:=1 to n do b[i]:=b[i-1]+a[i];
for i:=1 to n do
    begin
    l:=i;
    r:=n;
    while r-l>1 do
        begin
         k:=(l+r)div 2;
         if b[k]-b[i-1]>t then r:=k
                          else l:=k
        end;
    if b[n]-b[i-1]<=t then c[i]:=n-i+1
                      else if a[i]>t then c[i]:=0
                                        else c[i]:=l-i+1;
    end;
max:=0;
for i:=1 to n do if max<c[i] then max:=c[i];
write (max);


end.