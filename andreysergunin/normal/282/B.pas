var n,i,a,b,l:longint;
    x:int64;

begin
read (n);
for i:=1 to n do
        begin
         read (a,b);
         x:=x+a;
        end;
if x mod 1000>= 500 then l:=x div 1000+1
                    else l:=x div 1000;
for i:=1 to l do write ('G');
for i:=l+1 to n do write ('A');
end.