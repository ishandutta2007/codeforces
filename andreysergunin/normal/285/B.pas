var i,n,s,t,k: longint;
    a:array[1..100000] of longint;
begin
read (n,s,t);
for i:=1 to n do
    read(a[i]);
i:=s;
if s<>t then
    begin
     i:=a[i];
     inc(k);
     while (t<>i) and (i<>s) do
            begin
            i:=a[i];
            inc(k);
            end;
    if i=s then write ('-1')
           else write (k);
    end
    else write ('0')


end.