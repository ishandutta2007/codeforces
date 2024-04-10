var i:longint;
    s:string;
    f:boolean;
begin
f:=true;
for i:=1 to 8 do
        begin
        readln (s);
        if (s='WBWBWBWB') or (s='BWBWBWBW') then
                                            else f:=false;
        end;
if f then write ('YES')
     else write ('NO');
end.