program problem1;

var str1, str2: ansistring;
    i, diff, cnt: longWord;

begin
    readln( str1 );
    readln( str2 );
    
    if ( length( str1 ) <> length( str2 ) ) then
    begin
        writeln( 'NO' );
        halt;
    end;
    
    diff := 0;
    cnt := 0;
    for i := 1 to length( str1 ) do
    begin
        if ( str1[i] <> str2[i] ) then
            if ( diff = 0 ) then
            begin
                inc( cnt );
                diff := i;
            end
            else if ( cnt = 1 ) and ( str1[i] = str2[diff] ) and ( str1[diff] = str2[i] ) then
                inc( cnt )
            else
            begin
                writeln( 'NO' );
                halt;
            end;
    end;
    
    if ( cnt = 1 ) then
    begin
        writeln( 'NO' );
        halt;
    end;
    
    writeln( 'YES' );
end.