var n,i:longint;
    k:int64;
begin
//assign(input,'b.inp');reset(input);
//assign(output,'b.out');rewrite(output);
readln(n,k);
For i:=1 to n do
    begin
        if k mod 2=1 then
            begin
                writeln(i);
                halt;
            end;
        k:=k div 2;
    end;
end.