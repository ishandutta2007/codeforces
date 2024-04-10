var a,b:char;
    f:boolean;
begin
f:=true;
read (b);
while not eoln do
    begin
    read (a);
    if f and (b='0') then
        begin
        f:=false;
        end
        else write (b);
    b:=a;
    end;
if not(f) then write (b);
end.