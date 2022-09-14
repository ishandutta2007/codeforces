var a,b,n,i,j:longint;
    f,t:boolean;
begin
read (a,b,n);
j:=1;
        t:=false;
        for i:=0 to 9 do
                if ((a*10+i) mod b = 0) and not (t) then
                        begin
                        t:=true;
                        a:=a*10+i;
                        end;
if t then
        begin
        write (a);
        for i:=1 to n-1 do write ('0')
        end
        else write ('-1');
end.